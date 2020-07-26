package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"os/user"
	"path"
	"path/filepath"
	"strings"
)

var outputDir string

func init() {
	usr, err := user.Current()
	if err != nil {
		log.Fatal(err)
	}
	outputDir = path.Join(usr.HomeDir, ".emacs.d/snippets/c++-mode")
}

func clear() {
	snippets, err := filepath.Glob(path.Join(outputDir, "pclib-*"))
	if err != nil {
		log.Fatal(err)
	}
	for _, s := range snippets {
		if err := os.Remove(s); err != nil {
			log.Fatal(err)
		}
	}
}

func open(library string) *os.File {
	f, err := os.Create(path.Join(outputDir, "pclib-"+library))
	if err != nil {
		log.Fatal(err)
	}
	return f

}

func write(w io.Writer, header, library string, skipIncludes bool) {
	f, err := os.Open(header)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	scanner := bufio.NewScanner(f)
	var lines []string
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}

	i := 0
	if skipIncludes {
		for ; i < len(lines); i++ {
			if !strings.HasPrefix(lines[i], "#") && len(lines[i]) != 0 {
				break
			}
		}
	}

	fmt.Fprintf(w, `# -*- mode: snippet -*-
# name: %[1]s
# key: %[1]s
# --
`, library)
	for ; i < len(lines); i++ {
		fmt.Fprintln(w, lines[i])
	}
}

func main() {
	clear()

	headers, err := filepath.Glob("*.h")
	if err != nil {
		log.Fatal(err)
	}

	for _, header := range headers {
		library := strings.ReplaceAll(strings.TrimSuffix(header, ".h"), "_", "-")
		withMain := false
		if library == "macros" {
			library = "main"
			withMain = true
		}
		f := open(library)
		write(f, header, library, !withMain)
		if withMain {
			fmt.Fprintln(f, `
int main() {
  $0
}`)
		}
		f.Close()
		log.Printf("wrote snippet for %q", library)
	}
}
