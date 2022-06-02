import jwt from 'jsonwebtoken';

const secret = 'test';

//this middle ware is created as we wanted the creator id 
const auth = async (req, res, next) => {

    try {
        const token = req.headers.authorization.split(" ")[1];

        //<500 means no google login just done with email and password
        const isCustomAuth = token.length < 500;
        let decodedData;
        if (token && isCustomAuth) {
            decodedData = jwt.verify(token, secret);
            console.log("decoded data ", decodedData);
            req.userId = decodedData.id;
        }
        // else {
        //     //logic for google login
        // }

        next();

    } catch (err) {
        console.log(err)
    }

}

export default auth