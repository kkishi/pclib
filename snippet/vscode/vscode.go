package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"log"
	"os"
	"path/filepath"
	"strings"
)

func body(header string, main bool) []string {
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

	if main {
		return append(lines, []string{
			"",
			"int main() {",
			"  $0",
			"}",
		}...)
	}
	i := 0
	for ; i < len(lines); i++ {
		if !strings.HasPrefix(lines[i], "#") && len(lines[i]) != 0 {
			break
		}
	}
	return lines[i:]
}

// Snippet represents a single entry of VS Code snippets.
type Snippet struct {
	Prefix string   `json:"prefix"`
	Body   []string `json:"body"`
}

func main() {
	headers, err := filepath.Glob("*.h")
	if err != nil {
		log.Fatal(err)
	}

	snippets := make(map[string]Snippet)
	for _, header := range headers {
		library := strings.ReplaceAll(strings.TrimSuffix(header, ".h"), "_", "-")
		withMain := false
		if library == "macros" {
			withMain = true
		}
		snippets[library] = Snippet{
			Prefix: library,
			Body:   body(header, withMain),
		}
	}
	bs, err := json.MarshalIndent(snippets, "", "  ")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(string(bs))
}
