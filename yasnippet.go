package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
	"path"
	"strings"
)

var file = flag.String("file", "", "")

func main() {
	flag.Parse()

	f, err := os.Open(*file)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	scanner := bufio.NewScanner(f)
	var lines []string
	for scanner.Scan() {
		lines = append(lines, scanner.Text())
	}

	// Skip include lines.
	i := 0
	for ; i < len(lines); i++ {
		if !strings.HasPrefix(lines[i], "#include") && len(lines[i]) != 0 {
			break
		}
	}

	fmt.Printf(`# -*- mode: snippet -*-
# name: %[1]s
# key: %[1]s
# --
`, strings.TrimSuffix(path.Base(*file), ".h"))
	for ; i < len(lines); i++ {
		fmt.Println(lines[i])
	}
}
