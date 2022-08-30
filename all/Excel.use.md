# Excel

- `COUNTIFS` conditional count
- `INDEX` captur data on condition
```go
// Copy the value of
// The first cell 
// which value(itself [it could be a neighboring value]) is above 150 
=INDEX(A2:A16,MATCH(TRUE,INDEX(A2:A16>150,0),))
```
