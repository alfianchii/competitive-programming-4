package main

import "fmt"

func main() {
	stockSpanner := Constructor()

	fmt.Println(stockSpanner.Next(100)) // return 1
	fmt.Println(stockSpanner.Next(80))  // return 1
	fmt.Println(stockSpanner.Next(60))  // return 1
	fmt.Println(stockSpanner.Next(70))  // return 2
	fmt.Println(stockSpanner.Next(60))  // return 1
	fmt.Println(stockSpanner.Next(75))  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
	fmt.Println(stockSpanner.Next(85))  // return 6

	// fmt.Println(stockSpanner.Next(100)) // return 6
	// fmt.Println(stockSpanner.Next(100)) // return 6
}
