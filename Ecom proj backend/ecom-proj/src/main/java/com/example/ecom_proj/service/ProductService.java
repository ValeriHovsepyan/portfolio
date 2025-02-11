package com.example.ecom_proj.service;

import com.example.ecom_proj.model.Product;
import com.example.ecom_proj.repo.ProductRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class ProductService
{
    @Autowired
    ProductRepo repo;

    public List<Product> getAllProducts()
    {
        return repo.findAll();
    }

    public void addProduct(Product product)
    {
        repo.save(product);
    }

    public Product getProduct(int id)
    {
        return repo.findById(id).orElse(null);
    }

    public void deletProduct(int id)
    {
        repo.deleteById(id);
    }

    public void updateProduct(Product product)
    {
        repo.save(product);
    }

    public List<Product> getByCategory(String category)
    {
        List<Product> productsCategorizes = new ArrayList<Product>();
        for (Product product : getAllProducts())
        {
            if (product.getCategory().equals(category))
            {
                productsCategorizes.add(product);
            }
        }
        return productsCategorizes;
    }

    public List<Product> searchProduct(String keyword)
    {
        return repo.selectProducts(keyword);
    }
}
