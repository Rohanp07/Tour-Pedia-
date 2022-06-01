
import express from "express";

import { createTour, getTours } from "../controller/tour.js";

const router = express.Router();


router.post("/", createTour);
router.post("/", getTours);


export default router;