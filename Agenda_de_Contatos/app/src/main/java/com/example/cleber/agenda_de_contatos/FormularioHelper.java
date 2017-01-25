package com.example.cleber.agenda_de_contatos;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

/**
 * Created by Cleber on 18/01/2017.
 */

public class FormularioHelper {

    private EditText etNome;
    private EditText etEmail;
    private EditText etTelefone;
    private EditText etSite;
    private EditText etEnd;
    private ImageView ivFoto;
    private Button btnFoto;
    private Contato contato;

    public FormularioHelper(Formulario activite) {
        contato = new Contato();
        this.etNome = (EditText) activite.findViewById(R.id.etNome);
        this.etEmail = (EditText) activite.findViewById(R.id.etEmail);
        this.etTelefone = (EditText) activite.findViewById(R.id.etTelefone);
        this.etSite = (EditText) activite.findViewById(R.id.etSite);
        this.etEnd = (EditText) activite.findViewById(R.id.etEnd);
        this.ivFoto = (ImageView) activite.findViewById(R.id.ivFoto);
        this.btnFoto = (Button) activite.findViewById(R.id.btnFoto);
    }

    public Button getBotaoFoto(){
        return btnFoto;
    }

    public Contato  pegaContatoDoFormulario(){
        this.contato.setNome(etNome.getText().toString());
        this.contato.setEmail(etEmail.getText().toString());
        this.contato.setTelefone(String.valueOf(etTelefone.getText().toString()));
        this.contato.setSite(etSite.getText().toString());
        this.contato.setEnd(etEnd.getText().toString());
        this.contato.setFoto((String) ivFoto.getTag());

        return contato;
    }

    public void colocaNoFomulario(Contato contato){
        etNome.setText(contato.getNome());
        etEmail.setText(contato.getEmail());
        etTelefone.setText(contato.getTelefone());
        etSite.setText(contato.getSite());
        etEnd.setText(contato.getEnd());
        ivFoto.setTag(contato.getFoto());
        carregaImagem(contato.getFoto());
        this.contato = contato;
    }

    public void carregaImagem(String localFoto){
        if(localFoto!=null){
            Bitmap imagemfoto = BitmapFactory.decodeFile(localFoto);
            ivFoto.setImageBitmap(imagemfoto);
            ivFoto.setTag(localFoto);
        }
    }

}
