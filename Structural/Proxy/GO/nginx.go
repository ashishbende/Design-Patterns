package main

type nginx struct {
	application       *application
	maxAllowedRequest int
	rateLimiter       map[string]int
}

func newNginXServer() *nginx {
	return &nginx{
		application:       &application{},
		maxAllowedRequest: 2,
		rateLimiter:       make(map[string]int),
	}
}

func (n *nginx) handleRequest(url, method string) (int, string) {
	allowed := n.checkRateLimiting(url)
	if !allowed {
		return 403, "Not allowed"
	}
	return n.application.handleRequest(url, method)
}

func (n *nginx) checkRateLimiting(url string) bool {
	// first entry
	if n.rateLimiter[url] == 0 {
		n.rateLimiter[url] = 1
	}
	// limit exceeded
	if n.rateLimiter[url] > n.maxAllowedRequest {
		return false
	}
	// update entry
	n.rateLimiter[url] = n.rateLimiter[url] + 1
	return true
}
