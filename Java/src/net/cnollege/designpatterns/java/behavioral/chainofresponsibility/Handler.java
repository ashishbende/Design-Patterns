package net.cnollege.designpatterns.java.behavioral.chainofresponsibility;

public interface Handler{
    public void handleRequest(String request);
    public void setSuccessor(Handler next);
}