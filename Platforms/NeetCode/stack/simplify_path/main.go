package main

import "fmt"

func main() {
	// path := "/neetcode/practice//...///../courses"
	// path := "/..//"
	// path := "/..//_home/a/b/..///"
	path := "/a/./b/../../c/"

	result := SimplifyPath(path)

	fmt.Println(result)
}
