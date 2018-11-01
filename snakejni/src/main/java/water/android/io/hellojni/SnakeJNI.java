package water.android.io.hellojni;

public class SnakeJNI {

    static {
        System.loadLibrary("native-snake");
    }

    public native String getHelloWorld();
}
