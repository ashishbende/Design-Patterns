package main

type userCollection struct {
	users []*user
}

func (u *userCollection) createIterator() iIterator {
	return &userIterator{
		users: u.users,
	}
}
