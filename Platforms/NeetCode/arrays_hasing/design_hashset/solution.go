package main

import "slices"

type MyHashSet struct {
	buckets [][]int
}

func Constructor() MyHashSet {
	return MyHashSet{buckets: make([][]int, 10001)}
}

func (this *MyHashSet) Add(key int) {
	idx := this.hash(key)

	if !this.Contains(idx) {
		this.buckets[idx] = append(this.buckets[idx], key)
	}
}

func (this *MyHashSet) Remove(key int) {
	idx := this.hash(key)

	for i, v := range this.buckets[idx] {
		if v == key {
			this.buckets[idx] = append(
				this.buckets[idx][:i],
				this.buckets[idx][i+1:]...,
			)
			return
		}
	}
}

func (this *MyHashSet) Contains(key int) bool {
	idx := this.hash(key)

	return slices.Contains(this.buckets[idx], key)
}

func (this *MyHashSet) hash(key int) int {
	return key % len(this.buckets)
}
