package com.example.cleber.agenda_de_contatos;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.Image;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.List;

/**
 * Created by Cleber on 18/01/2017.
 */

public class ContatoAdapter extends BaseAdapter {

    private List<Contato> contatos;
    private Activity activity;

    public ContatoAdapter(List<Contato> contatos, Activity activity) {
        this.contatos = contatos;
        this.activity = activity;
    }


    @Override
    public int getCount() {
        return this.contatos.size();
    }

    @Override
    public Object getItem(int position) {
        return this.contatos.get(position);
    }

    @Override
    public long getItemId(int position) {
        return this.contatos.get(position).getId();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        View linha = convertView;
        Contato contato = contatos.get(position);
        Bitmap bitmap;

        if(linha==null){
            linha = this.activity.getLayoutInflater().inflate(R.layout.celula_contato,parent,false);
        }

        TextView tvNome = (TextView) linha.findViewById(R.id.tvCelulaNome);
        TextView tvTelefone = (TextView) linha.findViewById(R.id.tvCelulaTelefone);
        TextView tvSite = (TextView) linha.findViewById(R.id.tvCelulaSite);
        TextView tvEmail = (TextView) linha.findViewById(R.id.tvCelulaEmail);
        TextView tvEnd = (TextView) linha.findViewById(R.id.tvCelulaEnd);

        ImageView ivFoto = (ImageView) linha.findViewById(R.id.ivCelulaFoto);

        if(position%2==0){
            linha.setBackgroundColor(activity.getResources().getColor(R.color.par));
        }else{
            linha.setBackgroundColor(activity.getResources().getColor(R.color.impar));
        }

        tvNome.setText(contato.getNome());
        tvTelefone.setText(contato.getTelefone());

        if(tvSite!=null){
            tvSite.setText(contato.getSite());
        }
        if(tvEmail!=null){
            tvEmail.setText(contato.getEmail());
        }
        if(tvEnd!=null){
            tvEnd.setText(contato.getEnd());
        }
        if(contato.getFoto()!=null){
            bitmap = BitmapFactory.decodeFile(contato.getFoto());
        }else{
            bitmap = BitmapFactory.decodeResource(activity.getResources(), R.drawable.person);
        }

        //bitmap = Bitmap.createScaledBitmap(bitmap, 122,122,true);

        ivFoto.setImageBitmap(bitmap);
        return linha;
    }
}
