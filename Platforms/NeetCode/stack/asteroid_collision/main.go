package main

import "fmt"

func main() {
	asteroids := []int{2, 4, -4, -1}

	result := AsteroidCollision(asteroids)

	fmt.Println(result)
}
