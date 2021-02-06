package main

import "fmt"

type folder struct {
	// groups children
	components []iComponent
	name       string
}

func (f *folder) search(keyword string) {
	fmt.Println("Searching recursively for keyword", keyword, " in folder ", f.name)
	for _, composite := range f.components {
		composite.search(keyword)
	}
}

func (f *folder) add(c iComponent) {
	f.components = append(f.components, c)
}
