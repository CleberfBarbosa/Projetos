package com.example.cleber.agenda_de_contatos;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.v4.app.NavUtils;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import java.io.File;
import java.text.Normalizer;

public class Formulario extends AppCompatActivity {

    private Contato contato;
    private FormularioHelper formularioHelper;
    private String localArquivoFoto;
    private static final int TIRA_FOTO = 123;
    private boolean fotoResource = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_formulario);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        if (toolbar != null) {
            toolbar.setNavigationIcon(R.drawable.ic_chevron_left);
            toolbar.setNavigationOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    NavUtils.navigateUpFromSameTask(Formulario.this); //volta pro pai dela, definido no manifest
                    //finish();
                }
            });
        }
        this.formularioHelper = new FormularioHelper(Formulario.this);

        Intent intent = getIntent();
        this.contato = (Contato) intent.getSerializableExtra("ContatoSelecionado");
        if(contato != null){
            formularioHelper.colocaNoFomulario(contato);
        }

        final Button btnFoto = (Button) findViewById(R.id.btnFoto);
        btnFoto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                origemImagem();
            }
        });
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_formulario,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        switch (item.getItemId()){
            case R.id.formulario_ok:
                contato = formularioHelper.pegaContatoDoFormulario();
                ContatoDAO contatoDAO = new ContatoDAO(Formulario.this);
                if(contato.getId()==null){
                    contatoDAO.adicionarContato(contato);
                }else{
                    contatoDAO.editarContato(contato);
                }
                contatoDAO.close();
                Toast.makeText(getApplicationContext(),"Contato salvo.", Toast.LENGTH_SHORT).show();
                finish();
                return false;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void origemImagem(){
        new AlertDialog.Builder(Formulario.this)
                .setTitle(R.string.app_name)
                .setMessage("Escolha a origem da foto")
                .setPositiveButton("Camera", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        imagemCamera();
                    }
                })
                .setNegativeButton("Arquivos", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        imagemArquivos();
                    }
                })
                .show();
    }

    private void imagemCamera(){
        fotoResource = true;
        localArquivoFoto = getExternalFilesDir(null) + "/"+ System.currentTimeMillis()+".jpg";

        Intent irParaCamera = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        irParaCamera.putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(new File(localArquivoFoto)));
        startActivityForResult(irParaCamera, 123);
    }

    private void imagemArquivos(){
        fotoResource = false;
        Intent i = new Intent(Intent.ACTION_PICK,
                android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        startActivityForResult(i, 1);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        if(fotoResource){
            if (requestCode == TIRA_FOTO) {
                if(resultCode == Activity.RESULT_OK) {
                    formularioHelper.carregaImagem(this.localArquivoFoto);
                } else {
                    this.localArquivoFoto = null;
                }
            }
        }else{
            if (resultCode == RESULT_OK
                    && null != data) {

                Uri imagemSel = data.getData();
                String[] filePathColumn = { MediaStore.Images.Media.DATA };

                Cursor cursor = getContentResolver().query(imagemSel,
                        filePathColumn, null, null, null);
                cursor.moveToFirst();

                int columnIndex = cursor.getColumnIndex(filePathColumn[0]);
                String caminhoFoto = cursor.getString(columnIndex);
                cursor.close();

                formularioHelper.carregaImagem(caminhoFoto);
            }

        }


    }
}
