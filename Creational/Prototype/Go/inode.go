package main
// prototype interface
// responsibility to clone object is given to the object itself
type inode interface{
	print(string)
	clone() inode
}