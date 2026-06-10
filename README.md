# 🛒 Market Stok Takip Sistemi (C)

## Proje Hakkında
Bu proje, C programlama dili kullanılarak geliştirilmiş basit bir Market Stok Takip Sistemi uygulamasıdır. Program sayesinde ürün ekleme, listeleme, ürün arama, stok güncelleme, ürün silme ve dosya işlemleri gerçekleştirilebilir. Amaç, struct yapıları, fonksiyonlar, diziler ve dosya işlemleri konularını uygulamalı olarak kullanmaktır.

## Özellikler
- Ürün ekleme
- Ürün listeleme
- ID numarasına göre ürün arama
- Ürün silme
- Stok güncelleme
- Dosyaya kaydetme
- Dosyadan okuma

## Kullanılan Veri Yapısı

```c
typedef struct{
    int id;
    char ad[50];
    float fiyat;
    int stok;
} urun;
