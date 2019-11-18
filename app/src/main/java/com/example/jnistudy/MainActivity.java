package com.example.jnistudy;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    // Example of a call to a native method
    final TextView tv = findViewById(R.id.sample_text);
    findViewById(R.id.format_bt).setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            tv.setText(formatName(tv.getText().toString()));
        }
    });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    public native String formatName(String name);

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
