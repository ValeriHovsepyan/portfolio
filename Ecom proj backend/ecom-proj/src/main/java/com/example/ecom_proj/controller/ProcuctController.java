package com.example.ecom_proj.controller;

import com.example.ecom_proj.model.Product;
import com.example.ecom_proj.service.ProductService;
import org.hibernate.type.descriptor.jdbc.internal.DelayedStructJdbcType;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.http.server.DelegatingServerHttpResponse;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@CrossOrigin
@RequestMapping("/api")
public class ProcuctController
{
    @Autowired
    private ProductService productService;

    @RequestMapping("/products")
    public List<Product> getAllProducts()
    {
        return productService.getAllProducts();
    }

    @GetMapping("/product/{id}")
    public ResponseEntity<Product> getProduct(@PathVariable int id)
    {
        Product product = productService.getProduct(id);
        if (product == null)
            return new ResponseEntity<>(HttpStatus.NOT_FOUND);
        else
            return new ResponseEntity<>(product, HttpStatus.OK);
    }

    @PostMapping("/product")
    public void addProduct(@RequestPart Product product)
    {
        productService.addProduct(product);
    }

    @DeleteMapping("product/{id}")
    public void deleteProduct(@PathVariable int id)
    {
        productService.deletProduct(id);
    }

    @PutMapping("product/{id}")
    public void updateProduct(@RequestPart Product product, @PathVariable int id)
    {
        product.setId(id);
        productService.updateProduct(product);
    }

    @GetMapping("/products/categories/{category}")
    public List<Product> getByCategory(@PathVariable String category)
    {
        return productService.getByCategory(category);
    }

    @GetMapping("products/seatch")
    public List<Product> searchProducts(@RequestParam String keyword)
    {
       return productService.searchProduct(keyword);
    }
}
