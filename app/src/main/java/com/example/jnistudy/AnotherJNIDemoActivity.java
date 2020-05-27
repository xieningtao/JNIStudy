package com.example.jnistudy;

import android.os.Bundle;
import android.util.Log;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class AnotherJNIDemoActivity extends AppCompatActivity {
    private final String TAG = "AnotherJNIDemoActivity";

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_jni_demo);
        initView();
    }

    private void initView() {
        findViewById(R.id.basic_type_bt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                double result = testBasic(10, false);
                Log.d(TAG, "result: " + result);
            }
        });

        findViewById(R.id.object_type_bt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                testObject("hello world");
            }
        });

        findViewById(R.id.array_type_bt).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int arrayTest[] = {1, 2, 3, 4, 5};
                testArray(arrayTest);
            }
        });
    }

    private native double testBasic(int a, boolean value);

    private native double testObject(String value);

    private native double testArray(int[] values);

    private native double aaa(int a,double b);
}
