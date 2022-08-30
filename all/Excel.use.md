# Excel

- `Ctrl`+<kbd>&darr;</kbd> : jumpe to last value (before (not)empty)
- **Next value change** : Highlight the column you are interested in; Press `Ctrl+Shift+\`
- [Move selection]

### Functions
- `COUNTIFS` conditional count
- `INDEX` captur data on condition
```go
// Copy the value of
// The first cell 
// which value(itself [it could be a neighboring value]) is above 150 
=INDEX(A2:A16,MATCH(TRUE,INDEX(A2:A16>150,0),))
```

### Time
Converte number of second to time
```go
 =A2/86400
 ```
[Move selection]: https://superuser.com/a/673820
