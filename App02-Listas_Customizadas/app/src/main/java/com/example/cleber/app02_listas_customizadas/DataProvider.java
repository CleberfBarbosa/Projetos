package com.example.cleber.app02_listas_customizadas;

/**
 * Created by Cleber on 07/01/2017.
 */

public class DataProvider {
    private String marca, modelo;
    private int imagem;

    public DataProvider(String marca, String modelo, int imagem) {
        this.marca = marca;
        this.modelo = modelo;
        this.imagem = imagem;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public int getImagem() {
        return imagem;
    }
}
