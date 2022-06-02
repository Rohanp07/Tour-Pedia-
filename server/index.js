import express from "express";
import cors from "cors";
import mongoose from "mongoose";
import morgan from "morgan";

//routers
import userRouter from "./routes/user.js";
import tourRouter from "./routes/tour.js";


const app = express();
app.use(morgan('dev'));
app.use(express.json({ limit: "50mb", extended: true }));
app.use(express.urlencoded({ limit: "50mb", extended: true }));

app.use(cors()); 


//routers
app.use("/users", userRouter); //http://localhost:5000/users/
app.use("/tour", tourRouter);

const MONGODB_URL = "mongodb+srv://pratikvartak:pratikvartak@cluster0.cqaxl.mongodb.net/tour_db?retryWrites=true&w=majority";

const PORT = 5000;
mongoose.connect(MONGODB_URL).then(() => {
    app.listen(PORT, () => console.log(`server running on ${PORT}`))
})
    .catch((err) => console.log(`${err} did not connect`));



