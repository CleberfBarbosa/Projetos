package com.example.cleber.agenda_de_contatos;

import android.Manifest;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private ListView lvListaContatos;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Formulario.class);
                startActivity(intent);

            }
        });

        lvListaContatos = (ListView) findViewById(R.id.lvListaContatos);

        registerForContextMenu(lvListaContatos);

        lvListaContatos.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contato contato = (Contato) parent.getItemAtPosition(position);

                Intent intent = new Intent(getApplicationContext(), Formulario.class);
                intent.putExtra("ContatoSelecionado", contato);
                startActivity(intent);
            }
        });

        permissaoSms();
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {

        AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
        final Contato contatoSelecionado = (Contato) lvListaContatos.getAdapter().getItem(info.position);
        final MenuItem itemLigar = menu.add("Ligar");
        final MenuItem itemSms = menu.add("Enviar SMS");
        final MenuItem itemSite = menu.add("Ir para o site");
        final MenuItem itemApagar = menu.add("Apagar contato");

        itemApagar.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                new AlertDialog.Builder(MainActivity.this).
                        setIcon(android.R.drawable.ic_dialog_alert).
                        setTitle("Apagar").
                        setMessage("Deseja apagar contato?").
                        setPositiveButton("Sim", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                ContatoDAO contatoDAO = new ContatoDAO(MainActivity.this);
                                contatoDAO.apagarContato(contatoSelecionado);
                                contatoDAO.close();
                                carregaLista();
                            }
                        }).
                        setNegativeButton("Não", null).show();
                return false;
            }
        });

        itemLigar.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                new AlertDialog.Builder(MainActivity.this).
                        setIcon(android.R.drawable.ic_menu_call).
                        setTitle("Ligar").
                        setMessage("Deseja fazer ligação?").
                        setPositiveButton("Sim", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                permissaoLigar(contatoSelecionado);
                            }
                        }).
                        setNegativeButton("Não", null).
                        show();
                return false;
            }
        });

        itemSite.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                new AlertDialog.Builder(MainActivity.this).
                        setIcon(android.R.drawable.ic_popup_sync).
                        setTitle("Acessar site").
                        setMessage("Deseja acessar site?").
                        setPositiveButton("Sim", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                Intent intentSite = new Intent(Intent.ACTION_VIEW);
                                intentSite.setData(Uri.parse("http://"+contatoSelecionado.getSite()));
                                startActivity(intentSite);
                            }
                        }).
                        setNegativeButton("Não", null).
                        show();
                return false;
            }
        });

        itemSms.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem item) {
                new AlertDialog.Builder(MainActivity.this).
                        setIcon(android.R.drawable.ic_dialog_email).
                        setTitle("Enviar SMS").
                        setMessage("Deseja enviar sms?").
                        setPositiveButton("Sim", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                Intent intentSms = new Intent(Intent.ACTION_VIEW);
                                intentSms.setData(Uri.parse("sms:"+contatoSelecionado.getTelefone()));
                                startActivity(intentSms);
                            }
                        }).
                        setNegativeButton("Não", null).
                        show();
                return false;
            }
        });
        super.onCreateContextMenu(menu, v, menuInfo);
    }

    @Override
    protected void onResume() {
        carregaLista();
        super.onResume();
    }

    private void carregaLista() {
        ContatoDAO contatoDAO = new ContatoDAO(MainActivity.this);
        List<Contato> contatos = contatoDAO.listarContato();
        contatoDAO.close();
        ContatoAdapter contatoAdapter = new ContatoAdapter(contatos, this);
        lvListaContatos.setAdapter(contatoAdapter);
    }

    private void permissaoSms(){

        if (ActivityCompat.checkSelfPermission(MainActivity.this, Manifest.permission.RECEIVE_SMS) != PackageManager.PERMISSION_GRANTED) {
            if (!(ActivityCompat.shouldShowRequestPermissionRationale(MainActivity.this, Manifest.permission.RECEIVE_SMS))) {
                //Se entrar aqui é pq a permissão ainda nao foi negada, ele n pede a permissão mais de uma vez
                ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.RECEIVE_SMS}, 0);
            }
        }
    }

    private void permissaoLigar(Contato contato){

        //se nao possuir a permissao ainda ele entra no if
        if (ActivityCompat.checkSelfPermission(MainActivity.this, Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
            if (ActivityCompat.shouldShowRequestPermissionRationale(MainActivity.this, Manifest.permission.CALL_PHONE)) {
                //se a permissao ja tiver sido negada ele entra aqui
            }else{
                //Se entrar aqui é pq ainda nao possui a permissao e ela nao foi negada ainda
                ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.CALL_PHONE}, 0);
            }
        }else{//se entrar aqui é pq possui a permissao
            ligarContato(contato);
        }
    }

    private void ligarContato(Contato contato){
        if(contato !=null){
            Intent intentLigar = new Intent(Intent.ACTION_CALL);
            intentLigar.setData(Uri.parse("tel:" + contato.getTelefone()));
            startActivity(intentLigar);
        }

    }
}
