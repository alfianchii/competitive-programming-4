package main

import "fmt"

func main() {
	str := "2[a3[b]]c"

	result := DecodeString(str)

	fmt.Println(result)
}
