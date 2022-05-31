import mongoose from "mongoose";

const userSchema = mongoose.Schema({
    name: { type: String, required: true },
    email: { type: String, required: true },
    //we have kept password as false coz we are using both normal as well as 
    ///google login
    password: { type: String, required: false },
    googleId: { type: String, required: false },
    id: { type: String },
});


export default mongoose.model("User", userSchema);