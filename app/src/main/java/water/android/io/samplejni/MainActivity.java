package water.android.io.samplejni;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import water.android.io.snake.SnakeJNI;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText("Snake");

        SnakeJNI snakeJNI=new SnakeJNI();
        snakeJNI.nativeCreate();
        snakeJNI.nativeDestroy();
    }
}
