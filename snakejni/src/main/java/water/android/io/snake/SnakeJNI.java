package water.android.io.snake;

import android.util.Log;

public class SnakeJNI {

    static {
        System.loadLibrary("native-snake");
    }

    /**
     * native保存全局数据
     */
    private long nativeInstance;

    /**
     * native回调方法
     *
     * @param code
     */
    private void invokeCallback(int code) {
        Log.d("123", "code from native:" + code);
    }

    /**
     * native初始化
     */
    public native void nativeCreate();

    /**
     * native释放
     */
    public native void nativeDestroy();
}
