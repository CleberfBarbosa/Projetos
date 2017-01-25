package com.example.cleber.agenda_de_contatos;

import java.io.Serializable;

/**
 * Created by Cleber on 18/01/2017.
 */

public class Contato implements Serializable {

    private String nome, email, telefone, site, end, foto;
    private Long id;

    @Override
    public String toString() {
        return "(" + id + ")" + nome;
    }

    public String getNome() {
        return nome;
    }

    public String getEnd() {
        return end;
    }

    public String getEmail() {
        return email;
    }

    public String getSite() {
        return site;
    }

    public String getFoto() {
        return foto;
    }

    public String getTelefone() {
        return telefone;
    }

    public Long getId() {
        return id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEnd(String end) {
        this.end = end;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setSite(String site) {
        this.site = site;
    }

    public void setFoto(String foto) {
        this.foto = foto;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public void setId(Long id) {
        this.id = id;
    }
}
