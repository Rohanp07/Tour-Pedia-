import bcrypt from "bcryptjs";
import jwt from "jsonwebtoken";
import UserModel from "../models/user.js";


const secret = "test";

export const signIn = async (req, res) => {
    // console.log("in Login sigbUN ");
    const { email, password } = req.body;

    try {
        const userExist = await UserModel.findOne({ email });

        if (!userExist) {
            return res.status(400).json({ message: "User does not exist" });
        }

        const isPasswordCorrect = await bcrypt.compare(password, userExist.password);

        if (!isPasswordCorrect) return res.status(400).json({ message: "Credentials are incorrect" });

        const token = jwt.sign({ email: userExist.email, id: userExist._id }, secret, { expiresIn: "1h" });

        res.status(200).json({ result: userExist, token });
    } catch (err) {

        res.status(500).json({ message: "something went wrong" });
        console.log(err);

    }

}



export const signUp = async (req, res) => {

    const { email, password, firstName, lastName } = req.body;

    try {
        const userExists = await UserModel.findOne({ email });

        if (userExists) {
            return res.status(400).json({ message: "User already exists" });
        }

        //hashing the password
        const hashedPassword = await bcrypt.hash(password, 12);

        //creating the document
        const result = await UserModel.create({
            email,
            password: hashedPassword,
            name: `${firstName} ${lastName}`

        });

        //for jwt
        const token = jwt.sign({ email: result.email, id: result._id }, secret, { expiresIn: "1h" });

        res.status(201).json({ result, token });

    } catch (err) {

        res.status(500).json({ message: "something went wrong" });
        console.log(err);

    }


}
