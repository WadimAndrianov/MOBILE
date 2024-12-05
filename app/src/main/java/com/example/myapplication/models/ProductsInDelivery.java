package com.example.myapplication.models;

public class ProductsInDelivery extends Product {
    private String quantity;
    private String address;

    public ProductsInDelivery(String product_code, String product_name, String product_price,
                              String product_description, String imageUri,
                              String quantity, String address) {
        // Используем конструктор родительского класса (Product)
        super(product_code, product_name, product_price, product_description, imageUri);
        this.quantity = quantity;
        this.address = address;
    }

    public ProductsInDelivery() {
        super(); // Конструктор по умолчанию для Firebase
    }

    // Геттеры и сеттеры для новых полей
    public String getQuantity() {
        return quantity;
    }

    public void setQuantity(String quantity) {
        this.quantity = quantity;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

}
