use test

db.createCollection("publishers")
db.createCollection("books")

db.publishers.insertMany([
    {
      "publisher_id": "p0",
      "name": "Prentice HallJaico Publishing House",
      "address": {
        "country": "Albania",
        "city": "La Guajira",
        "pincode": "443001"
      },
      "annual_revenue": 90000
    },
    {
      "publisher_id": "p1",
      "name": "Westland Publications",
      "address": {
        "country": "Albania",
        "city": "La Guajira",
        "pincode": "443001"
      },
      "annual_revenue": 60000
    },
    {
      "publisher_id": "p2",
      "name": "Penguin Random House India",
      "address": {
        "country": "Angola",
        "city": "Luanda",
        "pincode": "2177"
      },
      "annual_revenue": 20000
    },
    {
      "publisher_id": "p3",
      "name": "Roli Books",
      "address": {
        "country": "American Samoa",
        "city": "Pago Pago",
        "pincode": "96799"
      },
      "annual_revenue": 20000
    },
    {
      "publisher_id": "p4",
      "name": "Rupa Publications",
      "address": {
        "country": "Albania",
        "city": "La Guajira",
        "pincode": "443001"
      },
      "annual_revenue": 40000
    },
    {
      "publisher_id": "p5",
      "name": "Hachette India",
      "address": {
        "country": "United States",
        "city": "Atlanta",
        "pincode": "30301"
      },
      "annual_revenue": 60000
    },
    {
      "publisher_id": "p6",
      "name": "Aleph Book Company",
      "address": {
        "country": "Andorra",
        "city": "PO Boxes",
        "pincode": "AD500"
      },
      "annual_revenue": 40000
    }
  ])

db.books.insertMany([
    {
      "book_id": "b0",
      "title": "0FFS9GCSN3",
      "authors": [
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        },
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a29",
          "author_name": "C1RFYGKEX5",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "3425128205"
        },
        {
          "author_id": "a7",
          "author_name": "1O2D550G83",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "0456452402"
        }
      ],
      "category": [
        "Biology",
        "Fiction",
        "Chemistry",
        "Biology"
      ],
      "edition": 4,
      "rating": 4,
      "price": 1716,
      "year": 2019,
      "publisher_id": "p6"
    },
    {
      "book_id": "b1",
      "title": "P1RTJIBCJY",
      "authors": [
        {
          "author_id": "a16",
          "author_name": "G1JO10OIGP",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4896830193"
        }
      ],
      "category": [
        "Math"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2033,
      "year": 2012,
      "publisher_id": "p1"
    },
    {
      "book_id": "b2",
      "title": "DPR07T82VQ",
      "authors": [
        {
          "author_id": "a7",
          "author_name": "1O2D550G83",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "0456452402"
        },
        {
          "author_id": "a27",
          "author_name": "2KZ16UK3C2",
          "university_name": "u9",
          "university_city": "c9",
          "author_country": "Albania",
          "author_contact_no": "9003327390"
        },
        {
          "author_id": "a25",
          "author_name": "SEXEPTQJ08",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "7063858570"
        },
        {
          "author_id": "a3",
          "author_name": "213L5BC69I",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "7854555927"
        }
      ],
      "category": [
        "Biology",
        "Biology",
        "Fiction",
        "Programming"
      ],
      "edition": 4,
      "rating": 4,
      "price": 825,
      "year": 2021,
      "publisher_id": "p4"
    },
    {
      "book_id": "b3",
      "title": "7CQN3DWC7Q",
      "authors": [
        {
          "author_id": "a26",
          "author_name": "YAJA2ZDR5P",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "5512494044"
        }
      ],
      "category": [
        "Math"
      ],
      "edition": 1,
      "rating": 1,
      "price": 526,
      "year": 2016,
      "publisher_id": "p5"
    },
    {
      "book_id": "b4",
      "title": "S7PS1K9774",
      "authors": [
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        },
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        },
        {
          "author_id": "a5",
          "author_name": "80DTSREWDN",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "3789201362"
        },
        {
          "author_id": "a3",
          "author_name": "213L5BC69I",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "7854555927"
        }
      ],
      "category": [
        "Biology",
        "Chemistry",
        "Fiction",
        "Programming"
      ],
      "edition": 4,
      "rating": 4,
      "price": 2967,
      "year": 2020,
      "publisher_id": "p4"
    },
    {
      "book_id": "b5",
      "title": "PE105XK21Y",
      "authors": [
        {
          "author_id": "a14",
          "author_name": "VRCQLLCCYZ",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "4536581186"
        },
        {
          "author_id": "a5",
          "author_name": "80DTSREWDN",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "3789201362"
        }
      ],
      "category": [
        "Chemistry",
        "Fiction"
      ],
      "edition": 2,
      "rating": 2,
      "price": 1037,
      "year": 2006,
      "publisher_id": "p2"
    },
    {
      "book_id": "b6",
      "title": "731J808HTW",
      "authors": [
        {
          "author_id": "a5",
          "author_name": "80DTSREWDN",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "3789201362"
        },
        {
          "author_id": "a13",
          "author_name": "B7E6SF2SAL",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "8192096486"
        },
        {
          "author_id": "a6",
          "author_name": "7A8KOGZCZ4",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "4999131002"
        }
      ],
      "category": [
        "Fiction",
        "Programming",
        "Math"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1907,
      "year": 2009,
      "publisher_id": "p0"
    },
    {
      "book_id": "b7",
      "title": "8IVD9WRU67",
      "authors": [
        {
          "author_id": "a29",
          "author_name": "C1RFYGKEX5",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "3425128205"
        }
      ],
      "category": [
        "Chemistry"
      ],
      "edition": 1,
      "rating": 1,
      "price": 1748,
      "year": 2009,
      "publisher_id": "p6"
    },
    {
      "book_id": "b8",
      "title": "K2DNIIGMBK",
      "authors": [
        {
          "author_id": "a20",
          "author_name": "ZAETYAUHI5",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4118908803"
        }
      ],
      "category": [
        "Fiction"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2563,
      "year": 2018,
      "publisher_id": "p5"
    },
    {
      "book_id": "b9",
      "title": "AP9MSWYDC7",
      "authors": [
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        }
      ],
      "category": [
        "Fiction"
      ],
      "edition": 1,
      "rating": 1,
      "price": 984,
      "year": 2014,
      "publisher_id": "p2"
    },
    {
      "book_id": "b10",
      "title": "AQHPREP2FI",
      "authors": [
        {
          "author_id": "a27",
          "author_name": "2KZ16UK3C2",
          "university_name": "u9",
          "university_city": "c9",
          "author_country": "Albania",
          "author_contact_no": "9003327390"
        },
        {
          "author_id": "a11",
          "author_name": "NGHFZUE7SF",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "7181682978"
        }
      ],
      "category": [
        "Biology",
        "Math"
      ],
      "edition": 2,
      "rating": 2,
      "price": 1822,
      "year": 2016,
      "publisher_id": "p6"
    },
    {
      "book_id": "b11",
      "title": "358YVB6NNO",
      "authors": [
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a16",
          "author_name": "G1JO10OIGP",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4896830193"
        },
        {
          "author_id": "a8",
          "author_name": "WSIBP4K9N7",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "4963819392"
        }
      ],
      "category": [
        "Fiction",
        "Math",
        "Programming"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1598,
      "year": 2022,
      "publisher_id": "p1"
    },
    {
      "book_id": "b12",
      "title": "J7HHGM94TG",
      "authors": [
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        },
        {
          "author_id": "a15",
          "author_name": "NAENFZETAA",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0643001449"
        }
      ],
      "category": [
        "Programming",
        "Fiction"
      ],
      "edition": 2,
      "rating": 2,
      "price": 734,
      "year": 2013,
      "publisher_id": "p2"
    },
    {
      "book_id": "b13",
      "title": "2D89HOKHIR",
      "authors": [
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        },
        {
          "author_id": "a22",
          "author_name": "160W4EXDR9",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "4095410472"
        }
      ],
      "category": [
        "Programming",
        "Biology"
      ],
      "edition": 2,
      "rating": 2,
      "price": 1012,
      "year": 2013,
      "publisher_id": "p1"
    },
    {
      "book_id": "b14",
      "title": "9XRKD99QTE",
      "authors": [
        {
          "author_id": "a2",
          "author_name": "RRQ6R65LMX",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8864124118"
        },
        {
          "author_id": "a7",
          "author_name": "1O2D550G83",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "0456452402"
        }
      ],
      "category": [
        "Biology",
        "Biology"
      ],
      "edition": 2,
      "rating": 2,
      "price": 863,
      "year": 2010,
      "publisher_id": "p1"
    },
    {
      "book_id": "b15",
      "title": "AEFG8JTAII",
      "authors": [
        {
          "author_id": "a11",
          "author_name": "NGHFZUE7SF",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "7181682978"
        },
        {
          "author_id": "a25",
          "author_name": "SEXEPTQJ08",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "7063858570"
        },
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        }
      ],
      "category": [
        "Math",
        "Fiction",
        "Fiction"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1301,
      "year": 2009,
      "publisher_id": "p4"
    },
    {
      "book_id": "b16",
      "title": "U68WIPAJA4",
      "authors": [
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        },
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a7",
          "author_name": "1O2D550G83",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "0456452402"
        }
      ],
      "category": [
        "Programming",
        "Fiction",
        "Biology"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1100,
      "year": 2005,
      "publisher_id": "p2"
    },
    {
      "book_id": "b17",
      "title": "AEIKK0U3LS",
      "authors": [
        {
          "author_id": "a7",
          "author_name": "1O2D550G83",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "0456452402"
        },
        {
          "author_id": "a23",
          "author_name": "ZACEMBPSU1",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "6350811815"
        },
        {
          "author_id": "a10",
          "author_name": "QBMEQC29Z3",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "3248669473"
        },
        {
          "author_id": "a3",
          "author_name": "213L5BC69I",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "7854555927"
        }
      ],
      "category": [
        "Biology",
        "Programming",
        "Fiction",
        "Programming"
      ],
      "edition": 4,
      "rating": 4,
      "price": 533,
      "year": 2022,
      "publisher_id": "p0"
    },
    {
      "book_id": "b18",
      "title": "6EKIFAKRVY",
      "authors": [
        {
          "author_id": "a21",
          "author_name": "IADPAHSMYD",
          "university_name": "u10",
          "university_city": "c10",
          "author_country": "Algeria",
          "author_contact_no": "9187940605"
        },
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        },
        {
          "author_id": "a15",
          "author_name": "NAENFZETAA",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0643001449"
        },
        {
          "author_id": "a1",
          "author_name": "DR05DI7VC3",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0244132619"
        }
      ],
      "category": [
        "Math",
        "Programming",
        "Fiction",
        "Math"
      ],
      "edition": 4,
      "rating": 4,
      "price": 529,
      "year": 2022,
      "publisher_id": "p2"
    },
    {
      "book_id": "b19",
      "title": "6RGU5P7A05",
      "authors": [
        {
          "author_id": "a10",
          "author_name": "QBMEQC29Z3",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "3248669473"
        }
      ],
      "category": [
        "Fiction"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2287,
      "year": 2018,
      "publisher_id": "p2"
    },
    {
      "book_id": "b20",
      "title": "AV7L7GZ0VK",
      "authors": [
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        }
      ],
      "category": [
        "Fiction"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2031,
      "year": 2006,
      "publisher_id": "p5"
    },
    {
      "book_id": "b21",
      "title": "K73OJ07GNN",
      "authors": [
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        }
      ],
      "category": [
        "Biology"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2088,
      "year": 2010,
      "publisher_id": "p4"
    },
    {
      "book_id": "b22",
      "title": "NNRNF3E593",
      "authors": [
        {
          "author_id": "a26",
          "author_name": "YAJA2ZDR5P",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "5512494044"
        }
      ],
      "category": [
        "Math"
      ],
      "edition": 1,
      "rating": 1,
      "price": 1233,
      "year": 2020,
      "publisher_id": "p6"
    },
    {
      "book_id": "b23",
      "title": "2SJ1Y6NS6C",
      "authors": [
        {
          "author_id": "a21",
          "author_name": "IADPAHSMYD",
          "university_name": "u10",
          "university_city": "c10",
          "author_country": "Algeria",
          "author_contact_no": "9187940605"
        }
      ],
      "category": [
        "Math"
      ],
      "edition": 1,
      "rating": 1,
      "price": 1331,
      "year": 2021,
      "publisher_id": "p2"
    },
    {
      "book_id": "b24",
      "title": "ZWAABY81MT",
      "authors": [
        {
          "author_id": "a11",
          "author_name": "NGHFZUE7SF",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "7181682978"
        },
        {
          "author_id": "a21",
          "author_name": "IADPAHSMYD",
          "university_name": "u10",
          "university_city": "c10",
          "author_country": "Algeria",
          "author_contact_no": "9187940605"
        },
        {
          "author_id": "a10",
          "author_name": "QBMEQC29Z3",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "3248669473"
        }
      ],
      "category": [
        "Math",
        "Math",
        "Fiction"
      ],
      "edition": 3,
      "rating": 3,
      "price": 852,
      "year": 2024,
      "publisher_id": "p1"
    },
    {
      "book_id": "b25",
      "title": "EN20S7H3F2",
      "authors": [
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a28",
          "author_name": "DJYM6S73EA",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "7255874112"
        },
        {
          "author_id": "a24",
          "author_name": "ACJQDBWTXX",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "7264251240"
        }
      ],
      "category": [
        "Fiction",
        "Programming",
        "Chemistry"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1838,
      "year": 2021,
      "publisher_id": "p1"
    },
    {
      "book_id": "b26",
      "title": "DX7KJIG2YA",
      "authors": [
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        }
      ],
      "category": [
        "Chemistry"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2959,
      "year": 2023,
      "publisher_id": "p3"
    },
    {
      "book_id": "b27",
      "title": "PN4HXDCVIQ",
      "authors": [
        {
          "author_id": "a10",
          "author_name": "QBMEQC29Z3",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "3248669473"
        }
      ],
      "category": [
        "Fiction"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2907,
      "year": 2011,
      "publisher_id": "p4"
    },
    {
      "book_id": "b28",
      "title": "Q7LFOXQYLY",
      "authors": [
        {
          "author_id": "a13",
          "author_name": "B7E6SF2SAL",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "8192096486"
        }
      ],
      "category": [
        "Programming"
      ],
      "edition": 1,
      "rating": 1,
      "price": 1004,
      "year": 2017,
      "publisher_id": "p6"
    },
    {
      "book_id": "b29",
      "title": "6RSKA18J03",
      "authors": [
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        },
        {
          "author_id": "a6",
          "author_name": "7A8KOGZCZ4",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "4999131002"
        }
      ],
      "category": [
        "Chemistry",
        "Math"
      ],
      "edition": 2,
      "rating": 2,
      "price": 751,
      "year": 2014,
      "publisher_id": "p1"
    },
    {
      "book_id": "b30",
      "title": "JV00V5ZHEJ",
      "authors": [
        {
          "author_id": "a19",
          "author_name": "A48PTPWLFZ",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "3551195092"
        },
        {
          "author_id": "a27",
          "author_name": "2KZ16UK3C2",
          "university_name": "u9",
          "university_city": "c9",
          "author_country": "Albania",
          "author_contact_no": "9003327390"
        }
      ],
      "category": [
        "Chemistry",
        "Biology"
      ],
      "edition": 2,
      "rating": 2,
      "price": 745,
      "year": 2021,
      "publisher_id": "p5"
    },
    {
      "book_id": "b31",
      "title": "FNA7I3W5LH",
      "authors": [
        {
          "author_id": "a27",
          "author_name": "2KZ16UK3C2",
          "university_name": "u9",
          "university_city": "c9",
          "author_country": "Albania",
          "author_contact_no": "9003327390"
        },
        {
          "author_id": "a20",
          "author_name": "ZAETYAUHI5",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4118908803"
        },
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        },
        {
          "author_id": "a21",
          "author_name": "IADPAHSMYD",
          "university_name": "u10",
          "university_city": "c10",
          "author_country": "Algeria",
          "author_contact_no": "9187940605"
        }
      ],
      "category": [
        "Biology",
        "Fiction",
        "Biology",
        "Math"
      ],
      "edition": 4,
      "rating": 4,
      "price": 2702,
      "year": 2018,
      "publisher_id": "p3"
    },
    {
      "book_id": "b32",
      "title": "7BEOX9XZMG",
      "authors": [
        {
          "author_id": "a23",
          "author_name": "ZACEMBPSU1",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "6350811815"
        },
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        },
        {
          "author_id": "a3",
          "author_name": "213L5BC69I",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "7854555927"
        },
        {
          "author_id": "a16",
          "author_name": "G1JO10OIGP",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4896830193"
        }
      ],
      "category": [
        "Programming",
        "Programming",
        "Programming",
        "Math"
      ],
      "edition": 4,
      "rating": 4,
      "price": 722,
      "year": 2024,
      "publisher_id": "p2"
    },
    {
      "book_id": "b33",
      "title": "VR5Z1G0P3P",
      "authors": [
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        }
      ],
      "category": [
        "Programming"
      ],
      "edition": 1,
      "rating": 1,
      "price": 798,
      "year": 2023,
      "publisher_id": "p0"
    },
    {
      "book_id": "b34",
      "title": "4VIPDW4VEY",
      "authors": [
        {
          "author_id": "a10",
          "author_name": "QBMEQC29Z3",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "3248669473"
        },
        {
          "author_id": "a25",
          "author_name": "SEXEPTQJ08",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "7063858570"
        }
      ],
      "category": [
        "Fiction",
        "Fiction"
      ],
      "edition": 2,
      "rating": 2,
      "price": 969,
      "year": 2015,
      "publisher_id": "p5"
    },
    {
      "book_id": "b35",
      "title": "5P4XAMHHPB",
      "authors": [
        {
          "author_id": "a26",
          "author_name": "YAJA2ZDR5P",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "5512494044"
        },
        {
          "author_id": "a2",
          "author_name": "RRQ6R65LMX",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8864124118"
        }
      ],
      "category": [
        "Math",
        "Biology"
      ],
      "edition": 2,
      "rating": 2,
      "price": 850,
      "year": 2023,
      "publisher_id": "p3"
    },
    {
      "book_id": "b36",
      "title": "3N6ZT8LJ0X",
      "authors": [
        {
          "author_id": "a1",
          "author_name": "DR05DI7VC3",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0244132619"
        }
      ],
      "category": [
        "Math"
      ],
      "edition": 1,
      "rating": 1,
      "price": 1850,
      "year": 2021,
      "publisher_id": "p0"
    },
    {
      "book_id": "b37",
      "title": "WWSAKCX1PU",
      "authors": [
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        },
        {
          "author_id": "a13",
          "author_name": "B7E6SF2SAL",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "8192096486"
        },
        {
          "author_id": "a8",
          "author_name": "WSIBP4K9N7",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "4963819392"
        },
        {
          "author_id": "a3",
          "author_name": "213L5BC69I",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "7854555927"
        }
      ],
      "category": [
        "Biology",
        "Programming",
        "Programming",
        "Programming"
      ],
      "edition": 4,
      "rating": 4,
      "price": 725,
      "year": 2024,
      "publisher_id": "p0"
    },
    {
      "book_id": "b38",
      "title": "KIJK0TBGWQ",
      "authors": [
        {
          "author_id": "a18",
          "author_name": "85ZNFQYKVO",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "7913264027"
        },
        {
          "author_id": "a10",
          "author_name": "QBMEQC29Z3",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "3248669473"
        },
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a22",
          "author_name": "160W4EXDR9",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "4095410472"
        }
      ],
      "category": [
        "Programming",
        "Fiction",
        "Fiction",
        "Biology"
      ],
      "edition": 4,
      "rating": 4,
      "price": 1529,
      "year": 2018,
      "publisher_id": "p3"
    },
    {
      "book_id": "b39",
      "title": "43XZWJ66I0",
      "authors": [
        {
          "author_id": "a11",
          "author_name": "NGHFZUE7SF",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "7181682978"
        }
      ],
      "category": [
        "Math"
      ],
      "edition": 1,
      "rating": 1,
      "price": 2358,
      "year": 2016,
      "publisher_id": "p4"
    },
    {
      "book_id": "b40",
      "title": "6UCL7ANHNI",
      "authors": [
        {
          "author_id": "a1",
          "author_name": "DR05DI7VC3",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0244132619"
        },
        {
          "author_id": "a28",
          "author_name": "DJYM6S73EA",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "7255874112"
        },
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        },
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        }
      ],
      "category": [
        "Math",
        "Programming",
        "Chemistry",
        "Chemistry"
      ],
      "edition": 4,
      "rating": 4,
      "price": 2751,
      "year": 2013,
      "publisher_id": "p0"
    },
    {
      "book_id": "b41",
      "title": "L7X373Y9WK",
      "authors": [
        {
          "author_id": "a6",
          "author_name": "7A8KOGZCZ4",
          "university_name": "u13",
          "university_city": "c13",
          "author_country": "Angola",
          "author_contact_no": "4999131002"
        },
        {
          "author_id": "a13",
          "author_name": "B7E6SF2SAL",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "8192096486"
        }
      ],
      "category": [
        "Math",
        "Programming"
      ],
      "edition": 2,
      "rating": 2,
      "price": 1342,
      "year": 2020,
      "publisher_id": "p2"
    },
    {
      "book_id": "b42",
      "title": "KPPN5GI797",
      "authors": [
        {
          "author_id": "a24",
          "author_name": "ACJQDBWTXX",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "7264251240"
        },
        {
          "author_id": "a11",
          "author_name": "NGHFZUE7SF",
          "university_name": "u11",
          "university_city": "c11",
          "author_country": "American Samoa",
          "author_contact_no": "7181682978"
        },
        {
          "author_id": "a13",
          "author_name": "B7E6SF2SAL",
          "university_name": "u5",
          "university_city": "c5",
          "author_country": "Andorra",
          "author_contact_no": "8192096486"
        }
      ],
      "category": [
        "Chemistry",
        "Math",
        "Programming"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1958,
      "year": 2011,
      "publisher_id": "p5"
    },
    {
      "book_id": "b43",
      "title": "WURSJIATAS",
      "authors": [
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        }
      ],
      "category": [
        "Biology"
      ],
      "edition": 1,
      "rating": 1,
      "price": 1857,
      "year": 2012,
      "publisher_id": "p5"
    },
    {
      "book_id": "b44",
      "title": "KQ2TJHZCJN",
      "authors": [
        {
          "author_id": "a23",
          "author_name": "ZACEMBPSU1",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "6350811815"
        },
        {
          "author_id": "a8",
          "author_name": "WSIBP4K9N7",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "4963819392"
        },
        {
          "author_id": "a15",
          "author_name": "NAENFZETAA",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0643001449"
        }
      ],
      "category": [
        "Programming",
        "Programming",
        "Fiction"
      ],
      "edition": 3,
      "rating": 3,
      "price": 2916,
      "year": 2023,
      "publisher_id": "p3"
    },
    {
      "book_id": "b45",
      "title": "40MA9D9UIJ",
      "authors": [
        {
          "author_id": "a2",
          "author_name": "RRQ6R65LMX",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8864124118"
        },
        {
          "author_id": "a16",
          "author_name": "G1JO10OIGP",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4896830193"
        },
        {
          "author_id": "a5",
          "author_name": "80DTSREWDN",
          "university_name": "u12",
          "university_city": "c12",
          "author_country": "Andorra",
          "author_contact_no": "3789201362"
        },
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        }
      ],
      "category": [
        "Biology",
        "Math",
        "Fiction",
        "Chemistry"
      ],
      "edition": 4,
      "rating": 4,
      "price": 1280,
      "year": 2022,
      "publisher_id": "p6"
    },
    {
      "book_id": "b46",
      "title": "WO2LELLSPP",
      "authors": [
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a23",
          "author_name": "ZACEMBPSU1",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "6350811815"
        },
        {
          "author_id": "a23",
          "author_name": "ZACEMBPSU1",
          "university_name": "u0",
          "university_city": "c0",
          "author_country": "United States",
          "author_contact_no": "6350811815"
        }
      ],
      "category": [
        "Fiction",
        "Programming",
        "Programming"
      ],
      "edition": 3,
      "rating": 3,
      "price": 1493,
      "year": 2023,
      "publisher_id": "p6"
    },
    {
      "book_id": "b47",
      "title": "VIG8IRGTPH",
      "authors": [
        {
          "author_id": "a17",
          "author_name": "DC6DJ6F5SI",
          "university_name": "u7",
          "university_city": "c7",
          "author_country": "United States",
          "author_contact_no": "2992570813"
        },
        {
          "author_id": "a12",
          "author_name": "MP2JMFT30L",
          "university_name": "u4",
          "university_city": "c4",
          "author_country": "American Samoa",
          "author_contact_no": "4222082444"
        }
      ],
      "category": [
        "Biology",
        "Biology"
      ],
      "edition": 2,
      "rating": 2,
      "price": 1935,
      "year": 2024,
      "publisher_id": "p1"
    },
    {
      "book_id": "b48",
      "title": "FEBQ2XZ4D9",
      "authors": [
        {
          "author_id": "a15",
          "author_name": "NAENFZETAA",
          "university_name": "u8",
          "university_city": "c8",
          "author_country": "Afghanistan",
          "author_contact_no": "0643001449"
        },
        {
          "author_id": "a21",
          "author_name": "IADPAHSMYD",
          "university_name": "u10",
          "university_city": "c10",
          "author_country": "Algeria",
          "author_contact_no": "9187940605"
        },
        {
          "author_id": "a20",
          "author_name": "ZAETYAUHI5",
          "university_name": "u6",
          "university_city": "c6",
          "author_country": "Angola",
          "author_contact_no": "4118908803"
        },
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        }
      ],
      "category": [
        "Fiction",
        "Math",
        "Fiction",
        "Chemistry"
      ],
      "edition": 4,
      "rating": 4,
      "price": 2909,
      "year": 2011,
      "publisher_id": "p5"
    },
    {
      "book_id": "b49",
      "title": "YGF12GJNVW",
      "authors": [
        {
          "author_id": "a0",
          "author_name": "B4ZAC982HO",
          "university_name": "u14",
          "university_city": "c14",
          "author_country": "United States",
          "author_contact_no": "4291794754"
        },
        {
          "author_id": "a4",
          "author_name": "S8OA8KIOYQ",
          "university_name": "u3",
          "university_city": "c3",
          "author_country": "Algeria",
          "author_contact_no": "8013503963"
        }
      ],
      "category": [
        "Fiction",
        "Chemistry"
      ],
      "edition": 2,
      "rating": 2,
      "price": 1829,
      "year": 2009,
      "publisher_id": "p5"
    }
  ])

-- 1
