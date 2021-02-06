package main

import "time"

type game struct {
	tPlayers  []*player
	ctPlayers []*player
}

func newGame() *game {
	return &game{}
}

func (g *game) addTerrorist(t string) {
	tp := newPlayer("Terrorist", t)
	tp.newLocation(time.Now().Second(), time.Now().Second()+2)
	g.tPlayers = append(g.tPlayers, tp)
}

func (g *game) addCounterTerrorist(ct string) {
	ctp := newPlayer("CounterTerrorist", ct)
	ctp.newLocation(time.Now().Second()+2, time.Now().Second())
	g.ctPlayers = append(g.ctPlayers, ctp)
}
