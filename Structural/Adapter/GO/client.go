package main

type client struct{}

func (c *client) insertSquareUsbInComputer(comp iComputer) {
	comp.insertInSquarePort()
}
