package main

import "fmt"

func main() {
	user1 := &user{
		name: "a",
		age:  30,
	}
	user2 := &user{
		name: "b",
		age:  20,
	}

	userCollection := &userCollection{
		users: []*user{user1, user2},
	}

	iter := userCollection.createIterator()
	for iter.hasNext() {
		user := iter.getNext()
		fmt.Printf("User is %+v\n", user)
	}
}
