package main

type windowsAdapter struct {
	windowsPC *windows
}

func (w *windowsAdapter) insertInSquarePort() {
	w.windowsPC.insertInCirclePort()
}
