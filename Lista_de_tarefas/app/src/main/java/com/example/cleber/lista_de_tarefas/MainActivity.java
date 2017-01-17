package com.example.cleber.lista_de_tarefas;

import android.app.DownloadManager;
import android.content.DialogInterface;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import static com.example.cleber.lista_de_tarefas.R.id.floatingActionButtonAdd;

public class MainActivity extends AppCompatActivity {

    private ListView lvListaTarefas;
    private EditText etNovaTarefa;
    private FloatingActionButton fabAdd;
    private SQLiteDatabase database;
    private ArrayAdapter<String> itensAdaptador;
    private ArrayList<Integer> ids;
    private ArrayList<String> tarefas;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lvListaTarefas = (ListView) findViewById(R.id.lvListaTarefas);
        etNovaTarefa = (EditText) findViewById(R.id.etNovaTarefa);
        fabAdd = (FloatingActionButton) findViewById(R.id.floatingActionButtonAdd);

        lvListaTarefas.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                alertaApagarTarefa(position);
                Log.i("LogX", Integer.toString(position));
                return false;
            }
        });
        carregaTarefas();

        fabAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                adicionaTarefas(etNovaTarefa.getText().toString());
            }
        });
    }

    private void carregaTarefas(){
        try {
            database = openOrCreateDatabase("ListaDeTarefas", MODE_PRIVATE, null);
            database.execSQL("CREATE TABLE IF NOT EXISTS tarefas (id INTEGER PRIMARY KEY AUTOINCREMENT, tarefa VARCHAR)");
            Cursor cursor = database.rawQuery("SELECT * FROM tarefas",null);
            cursor.moveToFirst();
            int colunaId = cursor.getColumnIndex("id");
            int colunaTarefa = cursor.getColumnIndex("tarefa");

            ids = new ArrayList<Integer>();
            tarefas = new ArrayList<String>();

            itensAdaptador = new ArrayAdapter<String>(getApplicationContext(),
                    android.R.layout.simple_list_item_1,
                    android.R.id.text1,
                    tarefas);
            lvListaTarefas.setAdapter(itensAdaptador);

            while(cursor != null){
                Log.i("LogX", "ID: " + cursor.getString(colunaId) +" TAREFA: " + cursor.getString(colunaTarefa));
                ids.add(Integer.parseInt(cursor.getString(colunaId)));
                tarefas.add(cursor.getString(colunaTarefa));
                cursor.moveToNext();
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    private  void adicionaTarefas(String tarefa){
        try {
            if(tarefa.length()>0){
                database.execSQL("INSERT INTO tarefas (tarefa) VALUES('" + tarefa + "')");
                Toast.makeText(getApplicationContext(), "Tarefa adicionada.", Toast.LENGTH_SHORT).show();
                carregaTarefas();
                etNovaTarefa.setText("");
            }else{
                Toast.makeText(getApplicationContext(), "Tarefa vazia, impossivel adicionar.", Toast.LENGTH_SHORT).show();
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    private void deletaTarefas(int id){
        try {
            database.execSQL("DELETE FROM tarefas WHERE id="+id);
            carregaTarefas();
            Toast.makeText(getApplicationContext(), "Tarefa removida.", Toast.LENGTH_SHORT).show();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    private void alertaApagarTarefa(Integer idSelecionado){
        String tarefaSelecionada = tarefas.get(idSelecionado);
        final Integer numeroId = idSelecionado;

        new AlertDialog.Builder(MainActivity.this).setTitle("Aviso")
                .setMessage("Deseja apagar a tarefa "+tarefaSelecionada+"?")
                .setPositiveButton("Sim", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        deletaTarefas(ids.get(numeroId));
                    }
                }).setNegativeButton("Não", null).show();
    }
}
