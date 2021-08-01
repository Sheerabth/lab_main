use test

// 1
db.publishers.find()

// 2
db.books.find({"title": "Understanding databases"})

// 3
db.books.find().sort({"rating": 1}).limit(3)

// 4
db.books.find({"authors.author_name": "Abraham silberschatz"})

// 5
db.books.find({"authors.author_country": "India"})

// 6
db.publishers.updateOne({"name": "Prentice Hall"}, {$set: {"address": {"country": "India", "city": "Chennai", "pincode": "600001"}}})

// 7
db.books.find({$and: [{"title": {$regex: "database", $options: "i"}}, {"price": {$lt: 500}}]})

// 8
db.books.find({$or: [{"category": "Science"}, {"category": "Maths"}]}).sort({"title": 1})

// 9
db.books.aggregate([{$unwind: "$authors"}, {$match: {"authors.author_country": "United States" }}, {$project: {"author_name": "$authors.author_name","author_contact_no": "$authors.author_contact_no", title:1, _id:0 }}])

// 10
db.books.find({"authors.0.author_name": "Abraham silberschatz"})

// 11
db.books.find({"year": {$gt: 2000}}, {"title": 1, "edition": 1, "price": 1})

// 12
db.books.count({rating: {$gt: 3}})

// 13

// 14
db.books.aggregate([{
   $lookup:
     {
       from: "publishers",
       localField: "publisher_id",
       foreignField: "publisher_id",
       as: "publisherDetails"
     }
}, {
    $match: {
        "title": "Database system concepts"
    }
}])

// 15
db.books.find({"title": {$regex: "data"}})

// 16
db.books.find({$and: [{"price": {$gt: 1000}}, {"rating": {$gt: 3}}]})

// 17
db.publishers.aggregate([
    {
        $group: {
          _id: "$address.city",
           Total_Revenue: { $sum: "$annual_revenue" }
        }
    },
    {
        $match: { "_id": "Delhi" }
    }
])

// 18
db.publishers.aggregate({)}