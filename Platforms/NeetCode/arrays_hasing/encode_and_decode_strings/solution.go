package main

import "strconv"

type Solution struct{}

func (this *Solution) Encode(strs []string) string {
	encodedStr := ""
	for _, str := range strs {
		encodedStr += strconv.Itoa(len(str)) + "#" + str
	}
	return encodedStr
}

func (this *Solution) Decode(encoded string) []string {
	res := []string{}

	i := 0
	for i < len(encoded) {
		j := i
		for encoded[j] != '#' {
			j++
		}

		length, _ := strconv.Atoi(encoded[i:j])
		i = j + 1

		res = append(res, encoded[i:i+length])
		i += length
	}

	return res
}
