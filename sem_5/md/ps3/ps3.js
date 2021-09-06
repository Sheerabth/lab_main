show databases
use spatial

db.neighborhoods.createIndex( { geometry : "2dsphere" } )

db.neighborhoods.insertOne({
    name: "custom_location",
    geometry: { type: "Point", coordinates: [ -110.8571443, 32.4586858 ] }
})

db.neighborhoods.find({
    name: "custom_location"
})

db.neighborhoods.updateOne({ name: "custom_location" }, { $set: { geometry: { type: "Point", coordinates: [ -110.8571443, 64.4586858 ] }}})

db.neighborhoods.deleteOne({ name: "custom_location" })

db.neighborhoods.find({ geometry : { $geoIntersects:
{ $geometry: { type: "Point", coordinates: [-73.97699848928194, 40.62987149612536],
} } } })

db.neighborhoods.find(
   {
     loc: {
       $geoWithin: {
          $geometry: {
             type : "Polygon" ,
             coordinates: [ [ [ -122.291909, 37.787745], [ -122.282663, 37.787745 ], [ -122.282663, 37.786430 ], [ -122.291909, 37.786430 ], [ -122.291909, 37.787745 ] ] ]
          }
       }
     }
   }
)