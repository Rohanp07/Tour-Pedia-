
import TourModel from '../models/tour.js';

export const createTour = async (req, res) => {

    const tour = req.body;
    const newTour = new TourModel({
        ...tour,
        creator: req.userId,
        createdAt: new Date().toISOString(),

    });

    try {
        await newTour.save();
        res.status(201).json(newTour);

    } catch (err) {
        console.log(err);
        res.status(404).json({ message: "something went wrong while creating tour" });
    }
}

export const getTours = async (req, res) => {

    try {
        const tours = await TourModel.find();
        res.status(200).json(tours);
    } catch (err) {
        res.status(404).json({ message: "something went wrong while getting tours" });
    }

}