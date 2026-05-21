# [Simplify Path](https://neetcode.io/problems/simplify-path/)

## Problem

You are given an absolute path for a Unix-style file system, which always begins with a slash `'/'`. Your task is to transform this absolute path into its **simplified canonical path**.

The rules of a Unix-style file system are as follows:

- A single period `'.'` represents the current directory.
- A double period `'..'` represents the previous/parent directory.
- Multiple consecutive slashes such as `'//'` and `'///'` are treated as a single slash `'/'.`
- Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, `'...'` and `'....'` are valid directory or file names.

The simplified canonical path should follow these rules:

- The path must start with a single slash `'/'`.
- Directories within the path must be separated by exactly one slash `'/'`.
- The path must not end with a slash `'/'`, unless it is the root directory.
- The path must not have any single or double periods (`'.'` and `'..'`) used to denote current or parent directories.

Return the simplified canonical path.

### Example 1

```go
Input: path = "/neetcode/practice//...///../courses"
Output: "/neetcode/practice/courses"
```

### Example 2

```go
Input: path = "/..//"
Output: "/"
```

### Example 3

```go
Input: path = "/..//_home/a/b/..///"
Output: "/_home/a"
```

### Constraints

- `1 <= path.length <= 3000`
- `path` consists of English letters, digits, period `'.'`, slash `'/'` or `'_'`
- `path` is a valid absolute Unix path

---

## Brute Force Intuition

Manually scan the path character by character and try to build the final path while handling slashes, dots, and directory names. This can work, but it is easy to make mistakes because `"."` only has special meaning when the whole directory name is exactly `"."`, and `".."` only has special meaning when the whole directory name is exactly `".."`. For example, `"..."`, `"...."`, `"a..b"`, and `"abc.def"` are valid directory names, not parent directory operations. So checking whether a string contains `".."` is incorrect.

## OK (Stack)

Split the path by `"/"` to get each directory segment. Then use a stack to store the valid directories that remain in the simplified path. At the end, join the stack using `"/"` and add one leading slash. If the stack is empty, return `"/"`.

## Complexity Analysis

- Time Complexity: `O(n)`
- Space Complexity: `O(n)`

## Edge Cases

- Valid directory names with more than two dots, for example `"/.../...."`
- Valid directory names that contain dots, for example `"/a..b/abc.def"`
