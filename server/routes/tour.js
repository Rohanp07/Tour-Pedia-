
import express from "express";
import auth from "../middleware/auth.js";

import { createTour, getTours, getTour, getToursByUser, deleteTour, updateTour, getToursBySearch, getToursByTag } from "../controller/tour.js";

const router = express.Router();


//getting tours by search 
router.get("/search", getToursBySearch);
router.get("/tag/:tag",getToursByTag);


//auth is used bcoz we need to  know who is the creator of post
router.post("/", auth, createTour);

router.get("/", getTours);
//we dont use auth as we dont need login to see single tour
router.get("/:id", getTour);

router.get("/userTours/:id", auth, getToursByUser);



//for update and delete
router.patch("/:id", auth, updateTour);
router.delete("/:id", auth, deleteTour);




export default router;