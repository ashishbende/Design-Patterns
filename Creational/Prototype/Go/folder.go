package main

import "fmt"

type folder struct{
	children []inode
	name string
}

func (f *folder)print(indentation string){
	fmt.Println(indentation + f.name)
	for _, i := range f.children{
		i.print(indentation+indentation)
	}
}

func (f *folder) clone() inode{
	cloneFolder := &folder{name: f.name+"_clone"}
	var tempChildrens []inode
	for _, i:=range f.children{
		cFileCopy := i.clone()
		tempChildrens =append(tempChildrens, cFileCopy)
		tempChildrens =append(tempChildrens, cFileCopy)
	}
	cloneFolder.children = tempChildrens
	return cloneFolder
}