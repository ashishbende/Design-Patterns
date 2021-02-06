package main

// flyweight pattern creates a sharable object for any instrinsic
// object property, that needs to be replicated among different different objects
type player struct {
	dress      iDress // instrinsic property
	playerType string
	lat        int
	long       int
}

func newPlayer(playerType, dressType string) *player {
	dress, _ := getDressFactorySingleInstance().getDressByType(dressType)
	return &player{
		playerType: playerType,
		dress:      dress,
	}
}

func (p *player) newLocation(lat, long int) {
	p.lat = lat
	p.long = long
}
