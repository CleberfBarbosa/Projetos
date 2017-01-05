package com.example.cleber.app01_conta_pessoas;

import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    int mulheres=0;
    int homens = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Button btnMulher = (Button) findViewById(R.id.btnMulher);
        final Button btnHomem = (Button) findViewById(R.id.btnHomem);
        Button btnResetar = (Button) findViewById(R.id.btnResetar);
        final TextView tvPessoas = (TextView) findViewById(R.id.tvPessoas);


        btnHomem.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                homens++;
                btnHomem.setText(Integer.toString(homens));
                tvPessoas.setText("Pessoas: "+Integer.toString(homens+mulheres));
            }
        });

        btnMulher.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mulheres++;
                btnMulher.setText(Integer.toString(mulheres));
                tvPessoas.setText("Pessoas: "+Integer.toString(homens+mulheres));
            }
        });

        btnResetar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tvPessoas.setText("Pessoas: 0");
                mulheres=0;
                homens=0;
                btnHomem.setText("0");
                btnMulher.setText("0");
            }
        });
    }

}
