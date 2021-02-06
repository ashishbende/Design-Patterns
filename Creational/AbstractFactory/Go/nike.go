package main

type nike struct{}

func (n *nike) makeShoe() iShoe{
	return &nikeShoe{
		shoe : shoe{
			logo : "Nike",
			size : 14,
		},
	}
}

func (n *nike) makeShort() iShort{
	return &nikeShort{
		short:short{
			logo:"Nike",
			size:14,
		},
	}
}
