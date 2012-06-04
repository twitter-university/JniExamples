package com.marakana.jniexamples;

public class Hello {

    public static native void sayHi(String who, int times); // <1>

    static {
        System.loadLibrary("hello"); // <2>
    }

    public static void main(String[] args) {
        sayHi(args[0], Integer.parseInt(args[1])); // <3>
    }
}
