package main

type adidas struct{}

func (a  *adidas) makeShoe() iShoe{
	return &adidasShoe{
		shoe: shoe{
			logo : "Adidas",
			size : 14,
		},
	}
}

func (a  *adidas) makeShort() iShort{
	return &adidasShort{
		short: short{
			logo : "Adidas",
			size : 32,
		},
	}
}