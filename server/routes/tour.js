
import express from "express";
import auth from "../middleware/auth.js";

import { createTour, getTours, getTour } from "../controller/tour.js";

const router = express.Router();


//auth is used bcoz we need to  know who is the creator of post
router.post("/", auth, createTour);

router.get("/", getTours);
//we dont use auth as we dont need login to see single tour
router.get("/:id", getTour);



export default router;