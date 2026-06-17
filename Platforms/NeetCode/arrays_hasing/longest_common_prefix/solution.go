package main

func LongestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	first := strs[0]
	for i, ch := range first {
		for _, str := range strs {
			if i >= len(str) || str[i] != byte(ch) {
				return first[:i]
			}
		}
	}

	return first
}
