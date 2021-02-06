package main
// concrete builder 2 - igloo
type iglooBuilder struct{
	windowType string
	doorType string
	floor int
}

func newIglooBuilder() *iglooBuilder{
	return &iglooBuilder{}
}

func (b *iglooBuilder) setWindowType(){
	b.windowType = "Wooden Window"
}

func (b *iglooBuilder) setDoorType(){
	b.doorType = "Wooden Door"
}

func (b *iglooBuilder) setNumFloor(){
	b.floor = 2
}

func (b *iglooBuilder) getHouse() house{
	return house{
		doorType : b.doorType,
		windowType : b.windowType,
		floor : b.floor,
	}
}