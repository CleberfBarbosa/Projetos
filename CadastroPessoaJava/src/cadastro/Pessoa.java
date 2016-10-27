/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cadastro;

/**
 *
 * @author Cleber
 */
public class Pessoa {

    public Pessoa(String nome, int idade, float altura, float peso, char sexo) {
        setNome(nome);
        setIdade(idade);
        setAltura(altura);
        setPeso(peso);
        setSexo(sexo);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if(nome.length()<6 || nome.length() > 100)
            throw new IllegalArgumentException();
        else
            this.nome = nome;
        
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        if(idade < 0 || idade > 100)
            throw new IllegalArgumentException();
        else
            this.idade = idade;
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        if(altura < 0.1)
            throw new IllegalArgumentException();
        else
            this.altura = altura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        if(peso < 0.1)
            throw new IllegalArgumentException();
        else
            this.peso = peso;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        if(sexo!='M' && sexo!='F')
            throw new IllegalArgumentException();
        else
            this.sexo = sexo;
    }
    
    private String nome;
    private int idade;
    private float altura, peso;
    private char sexo;  
}
