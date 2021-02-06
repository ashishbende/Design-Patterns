package main

type button struct {
	command iCommand
}

func (b *button) press() {
	b.command.execute()
}
